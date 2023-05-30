#include "SView.h"
#include "SController.h"
#include "SIndivObservers.h"

int main() {
	SView view;
	SController ctrl(view.GetModel());

	SCloseWindowObserver closeWindowObs(view);
	SJumpObserver jumpObs(view, ctrl);
	STickObserver jumpTimeObs(view, ctrl);
	SRightObserver rightObs(view, ctrl);
	SLeftObserver leftObs(view, ctrl);
	view.Show();
	return 0;
}