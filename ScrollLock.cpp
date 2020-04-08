#include <windows.h>

   void SetNumLock( BOOL bState )
   {
      BYTE keyState[256];

      GetKeyboardState((LPBYTE)&keyState);
      if( (bState && !(keyState[VK_SCROLL] & 1)) ||
          (!bState && (keyState[VK_SCROLL] & 1)) ) //Check if the scroll lock is off. Turn on scroll lock.
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
      } else { // Scroll lock is on, turn it off.
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
      SetNumLock(TRUE);
      return 0;
   }
