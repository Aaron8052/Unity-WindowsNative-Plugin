#include "pch.h"
#include "Notification.h"
#include "DesktopNotificationManagerCompat.h"
#include <NotificationActivationCallback.h>
#include <windows.ui.notifications.h>

using namespace ABI::Windows::Data::Xml::Dom;
using namespace ABI::Windows::UI::Notifications;
using namespace Microsoft::WRL;

void WindowsNative::Notification::PushNotification(const wchar_t* title, const wchar_t* content)
{

}
