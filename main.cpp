#include "UI/ui_filme.h"
#include "Service/service_filme.h"
#include "GUI/gui.h"
#include "Tests/Tests_Domain.h"
#include "Tests/Tests_Repository.h"
#include "Tests/test_all_service.h"
#include "Tests/Test_Validators.h"

int start_program(int argc, char ** argv){
    QApplication app(argc, argv);
    test_all_domain();
    test_all_repo();
    test_all_service();
    test_all_validators();
    Filme repo{};
    FilmeS service(&repo);
//    ui_filme ui(&service);
//    ui.run();
    gui g( &service);
    g.init_window();

    return QApplication::exec();
}

int main(int argc, char ** argv) {

    return start_program(argc, argv);

}
