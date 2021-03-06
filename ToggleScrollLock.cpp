#include <windows.h>

   void SetScrollLock()
   {
      BYTE keyState[256];

      GetKeyboardState((LPBYTE)&keyState);
      if(!(keyState[VK_SCROLL] & 1) ||
           (keyState[VK_SCROLL] & 1) )
      {
      // Simulate a key press
         keybd_event( VK_SCROLL,
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | 0,
                      0 );

      // Simulate a key release
         keybd_event( VK_SCROLL,
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      0);
      } else {
      	 // Simulate a key press
         keybd_event( VK_SCROLL,
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | 1,
                      1 );

      // Simulate a key release
         keybd_event( VK_SCROLL,
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      1);
	  }
   }

   int main()
   {
      SetScrollLock();
      return 0;
   }
