/*
 * ResultSheet_test.cpp
 *
 *  Created on: 2 de abr de 2020
 *      Author: joaopaulo
 */

#include "ResultSheet.h"
#include "catch.hpp"
TEST_CASE( "ResultSheet pode ser criada e linhas podem ser adicionadas", "[sheet]" ) {
	ResultSheet rsheet{};
	SECTION( "A ResultSheet é criada vazia" ) {
		REQUIRE( rsheet.HasNext() == false );
	}
	SECTION( "Ao adicionar uma linha a ResultSheet não é mais vazia" ) {
		rsheet.AddLine("1,2");
		REQUIRE( rsheet.HasNext() == true );
	}
	SECTION( "A primeira linha adicionada é a primeira a ser obtida" ) {
		std::string line1{"1,2,3,4"};
		std::string line2{"4,5,6,7"};
		rsheet.AddLine(line1);
		rsheet.AddLine(line2);
		REQUIRE( rsheet.HasNext() == true );
		REQUIRE( rsheet.NextLine() == line1 );
		REQUIRE( rsheet.NextLine() == line2 );
		REQUIRE( rsheet.HasNext() == false );
	}
}
