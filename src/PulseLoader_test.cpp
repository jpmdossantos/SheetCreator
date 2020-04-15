/*
 * PulseLoader_test.cpp
 *
 *  Created on: 2 de abr de 2020
 *      Author: joaopaulo
 */

#include "PulseLoader.h"
#include <iostream>
#include "catch.hpp"
TEST_CASE( "O PulseLoader pode ser iniciado", "[loader]" ) {

	PulseLoader pulse_loader{"./test_files"};

	SECTION( "O path passado para o pulse loader é salvo" ) {

		REQUIRE( pulse_loader.getMPath() =="./test_files" );
	}

	SECTION("Ao enviar um diretório sem arquivos de pulsos recebe uma excessão"){
		std::string erro;
		try{
			PulseLoader problem_loader{"./inexistent"};
		}
		catch(std::runtime_error& e)
		{
			erro = e.what();
		}
		REQUIRE( erro =="File not found" );
	}

	SECTION("Verifica se os pulsos estão sendo carregados corretamente"){
		auto pulses = pulse_loader.getMPulses();
		auto pulse1 = pulses.back();
		REQUIRE( pulse1["ID_Paciente"] == "324953" );
		REQUIRE( pulse1["wbc_count"] == "4027.9999999999986" );
		REQUIRE( pulse1["rbc_count"] == "33628.99999999998" );
		REQUIRE( pulse1["plt_count"] == "836.0");
		REQUIRE( pulse1["dif_count"] == "0");
		REQUIRE( pulse1["wbc_double_rate"] == "0.01264253842340109");
		REQUIRE( pulse1["rbc_double_rate"] == "0.030390436825359066");
		REQUIRE( pulse1["plt_double_rate"] == "0.0023923444976076554");
		REQUIRE( pulse1["wbc_double_pulses"] == "50.92414476945957");
		REQUIRE( pulse1["rbc_double_pulses"] == "1021.9999999999993");
		REQUIRE( pulse1["plt_double_pulses"] == "2.0");
		REQUIRE( pulse1["hgbs"] == "8148.0 4497.0");
	}

}
