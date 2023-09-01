#include <xloil/Throw.h>
#include <xloil/Log.h>
#include <xlOilHelpers/Exception.h>

namespace xloil
{
  XLOIL_EXPORT void logException(
    const char* path,
    const int line,
    const char* func,
    const char* msg) noexcept
  {
    try
    {
      auto lastSlash = strrchr(path, '\\');
      XLO_DEBUG("{0} (in {2}:{3} during {1})",
        msg, func, lastSlash ? lastSlash + 1 : path, line);
    }
    catch (...)
    {
    }
  }

  std::wstring writeWindowsError()
  {
    return Helpers::writeWindowsError();
  }
}