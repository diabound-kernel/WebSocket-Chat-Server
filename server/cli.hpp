#pragma once

#include "intro/metadata.hpp"

#include <CLI/CLI.hpp>

template<typename CLIConfig>
CLIConfig parseCLI(int argc, const char *argv[])
{
    CLI::App app{};

    CLIConfig config{};

    metadata::forEachField(config, [&](auto field) {
        app.add_option(
            std::string("--") +
                std::string(std::get<metadata::Field::Name>(field)),
            std::get<metadata::Field::Ref>(field));
    });

    try {
        app.parse(argc, argv);
    }
    catch (const ::CLI::ParseError &e) {
        std::cout << "Bad command line arguments. Error is {}. Exiting!"
                  << e.get_name() << std::endl;
        std::exit(app.exit(e));
    }

    return config;
}