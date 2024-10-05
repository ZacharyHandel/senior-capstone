#ifndef HEADERFOOTER_H
#define HEADERFOOTER_H

#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

class headerFooter : public Wt::WContainerWidget {
public:
    headerFooter(Wt::WContainerWidget *parent = nullptr);
    virtual ~headerFooter();

private:
    void setupHeader();
    void setupFooter();
};

#endif /* HEADERFOOTER_H */

