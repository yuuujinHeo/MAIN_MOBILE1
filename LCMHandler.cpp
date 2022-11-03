#include "LCMHandler.h"
#include <iostream>
#include <QDebug>

LCMHandler::LCMHandler()
    : lcm("udpm://239.255.76.67:7667?ttl=1")
{
    if(bThread == NULL){
        bFlag = true;
        bThread = new std::thread(&LCMHandler::bLoop, this);
    }
}

LCMHandler::~LCMHandler(){
    if(bThread != NULL)
    {
        bFlag = false;
        bThread->join();
    }
}


//void MainWindow::bt_Test()
//{
//    example_t send_msg;
//    send_msg.time = get_time();
//    lcm.publish("EXAMPLE", &send_msg);
//    printf("PUB: %f\n", send_msg.time);
//}


void LCMHandler::moveTo(int target_num){
    command send_msg;
    send_msg.cmd = ROBOT_CMD_MOVE_LOCATION;
    send_msg.params[0] = target_num;
    robot.curLocation = target_num;
    plog->write("[LCM] SEND COMMAND : MOVE LOCATION TO "+QString::number(target_num));
    lcm.publish("CMD",&send_msg);
}
void LCMHandler::moveTo(float x, float y, float th){
    command send_msg;
    send_msg.cmd = ROBOT_CMD_MOVE_TARGET;
    uint8_t *array;
    array = reinterpret_cast<uint8_t*>(&x);
    send_msg.params[0] = array[0];
    send_msg.params[1] = array[1];
    send_msg.params[2] = array[2];
    send_msg.params[3] = array[3];
    array = reinterpret_cast<uint8_t*>(&y);
    send_msg.params[4] = array[0];
    send_msg.params[5] = array[1];
    send_msg.params[6] = array[2];
    send_msg.params[7] = array[3];
    array = reinterpret_cast<uint8_t*>(&th);
    send_msg.params[8] = array[0];
    send_msg.params[9] = array[1];
    send_msg.params[10]= array[2];
    send_msg.params[11]= array[3];
    robot.curTarget.x = x;
    robot.curTarget.y = y;
    robot.curTarget.th = th;
    plog->write("[LCM] SEND COMMAND : MOVE TARGET TO "+QString().sprintf("%f, %f, %f",x,y,th));
    lcm.publish("CMD",&send_msg);
}
void LCMHandler::movePause(){
    command send_msg;
    send_msg.cmd = ROBOT_CMD_MOVE_PAUSE;
    send_msg.params[0] = 1;
    plog->write("[LCM] SEND COMMAND : MOVE PAUSE");
    lcm.publish("CMD",&send_msg);
}
void LCMHandler::moveResume(){
    command send_msg;
    send_msg.cmd = ROBOT_CMD_MOVE_PAUSE;
    send_msg.params[0] = 2;
    plog->write("[LCM] SEND COMMAND : MOVE RESUME");
    lcm.publish("CMD",&send_msg);
}
void LCMHandler::moveJog(float vx, float vy, float vth){
    command send_msg;
    send_msg.cmd = ROBOT_CMD_MOVE_JOG;
    uint8_t *array;
    array = reinterpret_cast<uint8_t*>(&vx);
    send_msg.params[0] = array[0];
    send_msg.params[1] = array[1];
    send_msg.params[2] = array[2];
    send_msg.params[3] = array[3];
    array = reinterpret_cast<uint8_t*>(&vy);
    send_msg.params[4] = array[0];
    send_msg.params[5] = array[1];
    send_msg.params[6] = array[2];
    send_msg.params[7] = array[3];
    array = reinterpret_cast<uint8_t*>(&vth);
    send_msg.params[8] = array[0];
    send_msg.params[9] = array[1];
    send_msg.params[10]= array[2];
    send_msg.params[11]= array[3];
    plog->write("[LCM] SEND COMMAND : MOVE TARGET TO "+QString().sprintf("%f, %f, %f",vx,vy,vth));
    lcm.publish("CMD",&send_msg);
}
void LCMHandler::moveStop(){
    command send_msg;
    send_msg.cmd = ROBOT_CMD_MOVE_STOP;
    plog->write("[LCM] SEND COMMAND : MOVE STOP");
    lcm.publish("CMD",&send_msg);
}
void LCMHandler::moveManual(){
    command send_msg;
    send_msg.cmd = ROBOT_CMD_MOVE_MANUAL;
    plog->write("[LCM] SEND COMMAND : MOVE MANUAL START");
    lcm.publish("CMD",&send_msg);
}
void LCMHandler::setVelocity(float vel, float velth){
    command send_msg;
    send_msg.cmd = ROBOT_CMD_SET_VELOCITY;
    uint8_t *array;
    array = reinterpret_cast<uint8_t*>(&vel);
    send_msg.params[0] = array[0];
    send_msg.params[1] = array[1];
    send_msg.params[2] = array[2];
    send_msg.params[3] = array[3];
    array = reinterpret_cast<uint8_t*>(&velth);
    send_msg.params[4] = array[0];
    send_msg.params[5] = array[1];
    send_msg.params[6] = array[2];
    send_msg.params[7] = array[3];
    plog->write("[LCM] SEND COMMAND : SET VELOCITY TO "+QString().sprintf("%f, %f",vel,velth));
    lcm.publish("CMD",&send_msg);
}


void LCMHandler::map_image_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const map_image_data *msg){
    qDebug() << "IMAGE SUB : " << msg->num;


}
void LCMHandler::map_metadata_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const map_meta_data *msg){
    qDebug() << "META SUB: "  << QString::fromStdString(msg->map_name);
    //clear
    map.locationTypes.clear();
    map.locationsPose.clear();

    map.map_name = QString::fromStdString(msg->map_name);
    map.width = msg->width;
    map.height = msg->height;
    map.gridwidth = msg->grid_width;
    map.origin[0] = msg->map_origin[0];
    map.origin[1] = msg->map_origin[1];
    map.locationSize = msg->num_loc;
    for(int i=0; i<map.locationSize; i++){
        ST_POSE temp_pose;
        map.locationTypes.push_back((int)msg->locations_type[i]);
        temp_pose.x = (int)msg->locations_x[i];
        temp_pose.y = (int)msg->locations_y[i];
        temp_pose.th = (int)msg->locations_th[i];
        map.locationsPose.push_back(temp_pose);
    }

}
void LCMHandler::robot_path_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const robot_path *msg){
    qDebug() << "PATH SUB : " << msg->num;

    //clear
    robot.curPath.clear();

    robot.pathSize = msg->num;
    for(int i=0; i<robot.pathSize; i++){
        ST_POSE temp_pose;
        temp_pose.x = (int)msg->path_x[i];
        temp_pose.y = (int)msg->path_y[i];
        temp_pose.th = (int)msg->path_th[i];
        robot.curPath.push_back(temp_pose);
    }


}
void LCMHandler::robot_pose_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const robot_pose *msg){
    qDebug() << "POSE SUB : " << msg->x << msg->y << msg->th;
    robot.curPose.x = msg->x;
    robot.curPose.y = msg->y;
    robot.curPose.th = msg->th;
}
void LCMHandler::robot_status_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const robot_status *msg){
    qDebug() << "STATUS SUB : " << msg->bat << msg->state << msg->err_code;
    robot.battery = msg->bat;
    robot.state = msg->state;
    robot.err_code = msg->err_code;
}
void LCMHandler::cmd_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const command *msg){
    qDebug() << "CMD SUB : " << msg->cmd;
}

void LCMHandler::bLoop()
{
    /*
    sudo ifconfig lo multicast
    sudo route add -net 224.0.0.0 netmask 240.0.0.0 dev lo
    */

    // lcm init
    if(lcm.good())
    {
        lcm.subscribe("IMAGE", &LCMHandler::map_image_callback, this);
        lcm.subscribe("META", &LCMHandler::map_metadata_callback, this);
        lcm.subscribe("PATH", &LCMHandler::robot_path_callback, this);
        lcm.subscribe("POSE", &LCMHandler::robot_pose_callback, this);
        lcm.subscribe("STATUS", &LCMHandler::robot_status_callback, this);
        lcm.subscribe("CMD", &LCMHandler::cmd_callback, this);
    }
    else
    {
        qDebug() << "lcm init failed";
    }

    while(bFlag)
    {
        lcm.handleTimeout(1);
    }
}
