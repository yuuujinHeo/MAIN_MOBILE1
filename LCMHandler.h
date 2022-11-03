#ifndef LCMHANDLER_H
#define LCMHANDLER_H

#include <QObject>
#include <QThread>
#include <chrono>
#include <thread>
#include <lcm/lcm-cpp.hpp>
#include "lcm_types/command.hpp"
#include "lcm_types/map_image_data.hpp"
#include "lcm_types/map_meta_data.hpp"
#include "lcm_types/robot_path.hpp"
#include "lcm_types/robot_pose.hpp"
#include "lcm_types/robot_status.hpp"
//#include "Supervisor.h"
#include "GlobalHeader.h"


class LCMHandler
{
public:
    LCMHandler();
    ~LCMHandler();
    // lcm
    lcm::LCM lcm;
    void map_image_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const map_image_data *msg);
    void map_metadata_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const map_meta_data *msg);
    void robot_path_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const robot_path *msg);
    void robot_pose_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const robot_pose *msg);
    void robot_status_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const robot_status *msg);
    void cmd_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const command *msg);

    void moveTo(int target_num);
    void moveTo(float x, float y, float th);
    void movePause();
    void moveResume();
    void moveJog(float vx, float vy, float vth);
    void moveStop();
    void moveManual();
    void setVelocity(float vel, float velth);

    // lcm message loop
    std::atomic<bool> bFlag;
    void bLoop();
    std::thread* bThread = NULL;
    bool isdownloadMap;
    ST_ROBOT    robot;
    ST_MAP      map;
};

#endif // LCMHANDLER_H
