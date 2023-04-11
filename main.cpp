#include "Vector/VectorClass.h"
#include "UI/ui_filme.h"
#include "Tests/Tests_Domain.h"
#include "Tests/Tests_Repository.h"
#include "Tests/test_all_service.h"
#include "Tests/Test_Validators.h"

void start_program(){
    test_all_domain();
    test_all_repo();
    test_all_service();
    test_all_validators();
    ui_filme ui;
    ui.run();
}

int main() {

    start_program();

    return 0;
}
