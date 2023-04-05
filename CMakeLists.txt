cmake_minimum_required(VERSION 3.25)
project(Lab6_7 CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab6_7 main.cpp Vector/VectorClass.cpp Vector/VectorClass.h Vector/Iterator.cpp Vector/Iterator.h Domain/Film.cpp Domain/Film.h Repository/Filme.cpp Repository/Filme.h Service/service_filme.cpp Service/service_filme.h UI/ui_filme.cpp UI/ui_filme.h Utils/utils.cpp Utils/utils.h Validator/validators.cpp Validator/validators.h Tests/Tests_Domain.cpp Tests/Tests_Domain.h Tests/Tests_Repository.cpp Tests/Tests_Repository.h Tests/test_all_service.cpp Tests/test_all_service.h Tests/Tests_Validators.cpp Tests/Test_Validators.h)