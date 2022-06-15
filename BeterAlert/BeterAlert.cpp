#include <Application.h>
#include "BeterAlert.h"
#include <TranslationUtils.h>
#include <TranslatorFormats.h> 

AlertWindow::AlertWindow():BAlert(" ", " ", "Ok"){
	BBitmap *peter = BTranslationUtils::GetBitmap(B_PNG_FORMAT,"peter.png");
	SetIcon(peter);
	ResizeBy(50, 0);
	CenterOnScreen();
}

bool AlertWindow::QuitRequested() {
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}

BeterAlert::BeterAlert():BApplication("application/BeterAlert") {
	BAlert *win = new AlertWindow();
	win->Show();
}

int main() {
	new BeterAlert();
	be_app->Run();
	delete be_app;
	return 0;	
}
