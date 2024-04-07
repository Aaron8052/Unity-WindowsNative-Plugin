/* 
	[Document]
	https://learn.microsoft.com/en-us/windows/apps/design/shell/tiles-and-notifications/send-local-toast-desktop-cpp-wrl
*/

#include "Notification.h"
#include <windows.h>
#include <wrl.h>
#include <windows.data.xml.dom.h>
#include <windows.ui.notifications.h>

using namespace ABI::Windows::Data::Xml::Dom;
using namespace ABI::Windows::UI::Notifications;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;

void WindowsNative::Notification::PushNotification(const wchar_t* title, const wchar_t* content)
{
    
}
