
#include <webots/robot.h>
#include <webots/motor.h>


#define TIME_STEP 64
#define MAX_SPEED 6

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  wb_robot_init();

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
WbDeviceTag w1=wb_robot_get_device("wheel1");
WbDeviceTag w2=wb_robot_get_device("wheel2");
WbDeviceTag w3=wb_robot_get_device("wheel3");
WbDeviceTag w4=wb_robot_get_device("wheel4");


wb_motor_set_position(w1, INFINITY);
wb_motor_set_position(w2, INFINITY);
wb_motor_set_position(w3, INFINITY);
wb_motor_set_position(w4, INFINITY);


wb_motor_set_velocity(w1, 0.0);

wb_motor_set_velocity(w2, 0.0);
wb_motor_set_velocity(w3, 0.0);
wb_motor_set_velocity(w4, 0.0);
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
wb_motor_set_velocity(w1, MAX_SPEED);
wb_motor_set_velocity(w2,MAX_SPEED);
wb_motor_set_velocity(w3, MAX_SPEED);
wb_motor_set_velocity(w4, MAX_SPEED);

  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}