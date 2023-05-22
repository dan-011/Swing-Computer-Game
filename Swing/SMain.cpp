#include "SView.h"
#include "SIndivObservers.h"

int main() {
	SView view;
	SCloseWindowObserver closeWindowObs(view);
	view.Show();
	return 0;
}