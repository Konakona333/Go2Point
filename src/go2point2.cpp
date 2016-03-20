#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Quaternion.h>
#include <tf/tf.h>
#include <geometry_msgs/Point.h>

geometry_msgs::Twist v;

void pointCallBack(const nav_msgs::OdometryConstPtr &qt)
{
    geometry_msgs::Quaternion p;
    p = qt->pose.pose.orientation;
    double yaw = tf::getYaw(p);
    
    geometry_msgs::Point gt;
    gt = qt->pose.pose.position;
    double x = gt.x;
    double y = gt.y;
    
    double xf = 4, yf = 1.5;
    
    double xr = xf - x;
    double yr = yf - y;
    
    double res = atan2(yr,xr) - yaw;
        
    
    
    if ()
    {
        v.linear.x = 1;
        v.angular.z = 0;
    }
    else
    {
        v.linear.x = 0;
        v.angular.z = 0.5;
    }
    
}

ros::Publisher go2pub;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "go2point2");
    
    ros::NodeHandle nh;
    
    ros::Subscriber go2sub = nh.subscribe("/vrep/vehicle/odometry", 1, pointCallBack);
    
    
    go2pub = nh.advertise<geometry_msgs::Twist>("go2point_topic", 1);
    
    
    ros::Rate loop_rate(50);
    
    
        
    
        
        
        
        
    ros::spinOnce();
    loop_rate.sleep();
}