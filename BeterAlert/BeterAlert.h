#include <Application.h>
#include <Alert.h>

class AlertWindow : public BAlert {
	public:
		AlertWindow();
		virtual bool QuitRequested();	
};

class BeterAlert : public BApplication {
	public:
		BeterAlert();
};
