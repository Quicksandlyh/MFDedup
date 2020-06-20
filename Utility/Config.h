//
// Created by Borelset on 2020/6/19.
//

#ifndef MFDEDUP_CONFIG_H
#define MFDEDUP_CONFIG_H

#include <string>
#include <iostream>
#include "toml.hpp"

extern std::string LogicFilePath;
extern std::string ClassFilePath;
extern std::string VersionFilePath;
extern std::string ManifestPath;
extern std::string KVPath;
extern std::string HomePath;
extern uint64_t RetentionTime;

class ConfigReader{
public:
    ConfigReader(std::string p){
        auto data = toml::parse(p);
        std::string path = toml::find<std::string>(data, "path");
        LogicFilePath = path + "/logicFiles/%lu";
        ClassFilePath = path + "/storageFiles/%lu";
        VersionFilePath = path + "/storageFiles/v%lu";
        ManifestPath = path + "/manifest";
        KVPath = path + "kvstore";
        HomePath = path;
        int64_t rt = toml::find<int64_t>(data, "retention");
        RetentionTime = rt;
        printf("-----------------------Configure-----------------------\n");
        printf("MFDedup storage path:%s, RetentionTime:%lu\n", path.data(), rt);
    }
private:
};

#endif //MFDEDUP_CONFIG_H
