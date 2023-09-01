
#include <xloil/StaticRegister.h>
#include <xloil/ArrayBuilder.h>
#include <xloil/Preprocessor.h>
#include <xloil/Version.h>
#include <xloil/Preprocessor.h>
#include <boost/preprocessor/seq/cat.hpp>

namespace xloil
{
#define OUR_VERSION (XLOIL_MAJOR_VERSION)(.)(XLOIL_MINOR_VERSION)(.)(XLOIL_PATCH_VERSION)

  XLO_FUNC_START(xloVersion())
  {
    constexpr wchar_t* version = XLO_WSTR(BOOST_PP_SEQ_CAT(OUR_VERSION));

    constexpr wchar_t* info[2][2] = { 
      { L"Version", version },
      { L"BuildDate", XLO_WSTR(__DATE__) } 
    };

    size_t stringLen = 0;
    for (auto i = 0; i < _countof(info); ++i)
      for (auto j = 0; j < _countof(info[i]); ++j)
        stringLen += wcslen(info[i][j]);
      
    ExcelArrayBuilder builder(2, 2, stringLen);
    for (auto i = 0; i < _countof(info); ++i)
      for (auto j = 0; j < _countof(info[i]); ++j)
        builder(i, j) = info[i][j];

    return returnValue(builder.toExcelObj());
  }
  XLO_FUNC_END(xloVersion).threadsafe()
    .help(L"Version info");
}