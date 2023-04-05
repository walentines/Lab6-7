//
// Created by Valentin Serban on 01.04.2023.
//

#include "../Validator/validators.h"

void test_check_number(){
    assert(check_number("123") == true);
    assert(check_number("dwad123") == false);
}

void test_validate_title(){
    assert(validate_title("") == false);
    assert(validate_title("afgaefgae") == true);
}

void test_validate_type(){
    assert(validate_type("") == false);
    assert(validate_type("gaegae") == true);
}

void test_validate_actor(){
    assert(validate_actor("") == false);
    assert(validate_actor("fgaegae") == true);
}

void test_validate_year(){
    assert(validate_year("fgaegae") == false);
    assert(validate_year("2000") == true);
    assert(validate_year("") == false);
}

void test_validate_id(){
    assert(validate_id("200") == true);
    assert(validate_id("gaieg") == false);
    assert(validate_id("") == false);

}

void test_all_validators(){
    test_check_number();
    test_validate_title();
    test_validate_type();
    test_validate_actor();
    test_validate_year();
    test_validate_id();
}
