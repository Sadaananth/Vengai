#include "visualize/Application.hpp"

#include "src/Logger.hpp"

using namespace Sada;

int main()
{
    Logger::instance().add_sink(Logger::Sink::console, LogLevel::Info);
    LOG_INFO << "Creating Application";

    Application application{{"Vengai-gui", 1080, 720}};
    application.render();
    return 0;
}
