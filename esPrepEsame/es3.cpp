#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;

class Component;

class Container {
public:
virtual ~Container();
vector<Component*> getComponents() const;
};

class Component: public Container {};

class Button: public Component {
public:
vector<Container*> getContainers() const;
};

class MenuItem: public Button {
public:
void setEnabled(bool b = true);
};



class NoButton {};
Button** Fun(const Container& c) {
    vector<Component*> vec = c.getComponents();
    if(vec.size()==0)
        return nullptr;
    int count = 0;
    for(vector<Component*>::const_iterator it=vec.begin(); it!=vec.end(); ++it) {
        auto *p = dynamic_cast<Button*>(*it);
        if(p)
            count++;
    }
    Button** ris = new Button*[count];
    int i = 0;
    for(vector<Component*>::const_iterator it=vec.begin(); it!=vec.end(); ++it) {
        auto *p = dynamic_cast<Button*>(*it);
        if(p) {
            auto *p2 = dynamic_cast<MenuItem*>(*it);
            if(p2&&p2->getContainers().size()>=2) {
                p2->setEnabled(false);
            }
            ris[i] = dynamic_cast<Button*>(*it);
            i++;
        }
    }
    return ris;
}