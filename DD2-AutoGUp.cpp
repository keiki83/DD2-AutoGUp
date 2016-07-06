// Developed by Keiki83

#define version 1.03
#include <windows.h>
#include <stdlib.h>
#include <iostream>

void PrintChat(HWND, std::string);
void TransmitKeyStrokes(HWND, std::string);

int main() {
  // Adjust Console size
  system("mode 70, 10");

  // Get DD2 window handle
  HWND gameWindow = FindWindow(NULL, "Dungeon Defenders 2");
  if(gameWindow == NULL) {
    std::cout << "ERROR: Dungeon Defenders 2 is not running." << std::endl;
    std::cout << "DD2-AutoGUp closing in 10 seconds..." << std::endl;
    Sleep(10000);
    return 0;
  }

  // Information
  std::cout << "DD2-AutoGUp was written by Keiki83, version " <<
    version << std::endl;
  std::cout << "This program is automatic and will detect your interaction with DD2.\n" <<
    "You do not need to start and stop the program.\n" <<
    "Simply tab-out for DD2-AutoGUp to take over.\n" << std::endl;

  // Primary Loop
  PrintChat(gameWindow, "Player has started DD2-AutoGUp");
  std::cout << "DD2-AutoGUp executing in 10 seconds..." << std::endl;
  Sleep(10000);
  std::cout << "DD2-AutoGUp executing NOW!" << std::endl;
  while(true) {
    if(gameWindow != GetForegroundWindow())
      TransmitKeyStrokes(gameWindow, "EG");
    Sleep(3000);
  }

  return 0;
}

// Trasmit key strokes to arg1 based on contents of arg2
void TransmitKeyStrokes(HWND window, std::string value) {
  for(int i = 0; i < (int)value.length(); i++) {
    SendMessage(window, WM_KEYDOWN, value[i], 0);
    SendMessage(window, WM_KEYUP, value[i], 0);
  }
}

// Trasmit message of arg2 to player chat screen (arg1)
void PrintChat(HWND window, std::string message) {
  SendMessage(window, WM_KEYDOWN, VK_RETURN, 0);
  SendMessage(window, WM_KEYUP, VK_RETURN, 0);
  for(int i = 0; i < (int)message.length(); i++)
    SendMessage(window, WM_CHAR, message[i], 0);
  SendMessage(window, WM_KEYDOWN, VK_RETURN, 0);
  SendMessage(window, WM_KEYUP, VK_RETURN, 0);
}
