#include <windows.h>
LRESULT CALLBACK MainWinProc(HWND, UINT, WPARAM, LPARAM);
#define ID_MYBUTTON 1 /* идентификатор для кнопки внутри главного окна */
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int ss) {
  /* создаем и регистрируем класс главного окна */
  WNDCLASS wc;
  wc.style = 0; wc.lpfnWndProc = MainWinProc; wc.cbClsExtra = wc.cbWndExtra = 0;
  wc.hInstance = hInst; wc.hIcon = NULL; wc.hCursor = NULL;
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); wc.lpszMenuName = NULL; 
  wc.lpszClassName = L"Example MainWnd Class";
  if (!RegisterClass(&wc)) return FALSE; /* создаем главное окно и отображаем его */
  HWND hMainWnd = CreateWindow(L"Example MainWnd Class", L"Nice button, dude ",
    WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
    CW_USEDEFAULT, NULL, NULL, hInst, NULL);
  if (!hMainWnd) return FALSE;
  ShowWindow(hMainWnd, ss);
  UpdateWindow(hMainWnd);

  MSG msg; /* цикл обработки событий */
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  } 
  return msg.wParam;
}
/* процедура обработки сообщений для главного окна */
LRESULT CALLBACK MainWinProc(HWND hw, UINT msg, WPARAM wp, LPARAM Ip) {
  switch (msg) {
  case WM_CREATE:
    CreateWindow(L"Button", L"Very good button", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 50, 50, 200, 30, hw, (HMENU)ID_MYBUTTON, NULL, NULL); return 0;
  case WM_COMMAND: /* нажата наша кнопка? */
    if ((HIWORD(wp) == 0) && (LOWORD(wp) == ID_MYBUTTON))
      MessageBox(hw, L"You pressed my button, holy shit", L"ClickBox", MB_OK | MB_ICONWARNING); return 0;
  case WM_DESTROY: /* пользователь закрыл окно, программа может завершаться */
    PostQuitMessage(0); return 0;
  }
  return DefWindowProc(hw, msg, wp, Ip);
}
