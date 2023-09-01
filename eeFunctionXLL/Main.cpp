#include <xloil/xlOil.h>
#include <xloil/XllEntryPoint.h>
using namespace xloil;

struct MyAddin
{};
XLO_DECLARE_ADDIN(MyAddin);

XLO_FUNC_START(
    MyFunc(const ExcelObj* arg1, const ExcelObj* arg2)
)
{
    auto result = arg1->toString() + ": " + arg2->toString(L"default value");
    return ExcelObj::returnValue(result);
}
XLO_FUNC_END(MyFunc).threadsafe()
.help(L"Joins two strings")
.arg(L"Val1", L"First String")
.arg(L"Val2", L"Second String");