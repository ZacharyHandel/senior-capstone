#include <memory>

#include <Wt/WApplication.h>

#include "casApp.h"

int 
main(int argc, char** argv)
{
	return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
		return std::make_unique<casApp>(env);
	});	
}
