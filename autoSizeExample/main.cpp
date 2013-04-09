#include <QtGui/QApplication>
#include "windowsstarted.h"
#include "compiler.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WindowsStarted w;
    w.show();
    return a.exec();
}
