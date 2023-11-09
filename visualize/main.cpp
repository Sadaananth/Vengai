#include "visualize/Application.hpp"

int main()
{
    Application application{{"Vengai-gui", 1080, 720}};
    application.render();
    return 0;
}
