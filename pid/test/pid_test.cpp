#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <typeinfo>
#include "Fixture.h"
#include "SystemModel.h"
#include <fstream>

extern "C" {
#include "pid.h"
#include "pid_externals.h"
#include "error_codes.h"
}

using namespace ::testing;
using ::testing::Return;

class RteTest: public Fixture{
public:
  RteTest(){}
};

TEST_F(RteTest, InitReturnValue) {
  EXPECT_CALL(*_rte, rte_pid_read_params(_))
    .Times(1)
    .WillOnce(Return(ERR_MEM_ACCES));
  uint8_t result = init_pid();
  EXPECT_EQ(result, ERR_MEM_ACCES);
}

TEST_F(RteTest, InitInputValues) {
  EXPECT_CALL(*_rte, rte_pid_read_params(_));
  init_pid();
  EXPECT_EQ(current_value, 0);
  EXPECT_EQ(typeid(int32_t), typeid(current_value));
  EXPECT_EQ(target_value, 0);
  EXPECT_EQ(typeid(int32_t), typeid(target_value));
  EXPECT_EQ(elapsed_time, PID_TASK_TIME);
  EXPECT_EQ(typeid(uint32_t), typeid(elapsed_time));
  EXPECT_EQ(control_signal, 0);
  EXPECT_EQ(typeid(int32_t), typeid(control_signal));
}

TEST_F(RteTest, InitReadParameters) {
  using ::testing::SetArgPointee;
  PidParams in_par;
  in_par.p = 1;
  in_par.i = 2;
  in_par.d = 3;
  in_par.i_pos_min = 4;
  in_par.i_neg_min = 5;
  in_par.i_pos_max = 6;
  in_par.i_neg_max = 7;
  in_par.o_pos_min = 8;
  in_par.o_neg_min = 9;
  in_par.o_pos_max = 10;
  in_par.o_neg_max = 11;
  in_par.calibrated = 0;

  EXPECT_CALL(*_rte, rte_pid_read_params(_))
    .Times(1)
    .WillOnce(DoAll(SetArgPointee<0>(in_par),
                    Return(ERR_OK)));
  uint8_t result = init_pid();
  EXPECT_EQ(parameters.p, in_par.p);
  EXPECT_EQ(parameters.i, in_par.i);
  EXPECT_EQ(parameters.d, in_par.d);
  EXPECT_EQ(parameters.i_pos_min, in_par.i_pos_min);
  EXPECT_EQ(parameters.i_neg_min, in_par.i_neg_min);
  EXPECT_EQ(parameters.i_pos_max, in_par.i_pos_max);
  EXPECT_EQ(parameters.i_neg_max, in_par.i_neg_max);
  EXPECT_EQ(parameters.o_pos_min, in_par.o_pos_min);
  EXPECT_EQ(parameters.o_neg_min, in_par.o_neg_min);
  EXPECT_EQ(parameters.o_pos_max, in_par.o_pos_max);
  EXPECT_EQ(parameters.o_neg_max, in_par.o_neg_max);
  EXPECT_EQ(parameters.calibrated, in_par.calibrated);
  EXPECT_EQ(result, ERR_OK);
} 

TEST_F(RteTest, TargetValue) {
  using ::testing::SetArgPointee;
  PidParams in_par;
  in_par.i_pos_min = 10;
  in_par.i_neg_min = 15;
  in_par.i_pos_max = 1000;
  in_par.i_neg_max = 900;

  EXPECT_CALL(*_rte, rte_pid_read_params(_))
    .Times(1)
    .WillOnce(DoAll(SetArgPointee<0>(in_par), Return(ERR_OK)));
  EXPECT_CALL(*_rte, rte_pid_read_target_value(_))
    .Times(5)
    .WillOnce(DoAll(SetArgPointee<0>(12), Return(ERR_MEM_ACCES)))
    .WillOnce(DoAll(SetArgPointee<0>(9), Return(ERR_OK)))
    .WillOnce(DoAll(SetArgPointee<0>(-14), Return(ERR_OK)))
    .WillOnce(DoAll(SetArgPointee<0>(1001), Return(ERR_OK)))
    .WillOnce(DoAll(SetArgPointee<0>(-901), Return(ERR_OK)));
  EXPECT_CALL(*_rte, rte_pid_read_current_value(_))
    .Times(4);
  EXPECT_CALL(*_rte, rte_pid_read_elapsed_time(_))
    .Times(4);
  init_pid();
  // Error reading:
  uint8_t result = read_inputs();
  EXPECT_EQ(result, ERR_MEM_ACCES);
  // Reading low positive value:
  result = read_inputs();
  EXPECT_EQ(target_value, 0);
  EXPECT_EQ(result, ERR_OK);
  // Reading low negative value:
  result = read_inputs();
  EXPECT_EQ(target_value, 0);
  EXPECT_EQ(result, ERR_OK);
  // Reading high positive value:
  result = read_inputs();
  EXPECT_EQ(target_value, parameters.i_pos_max);
  EXPECT_EQ(result, ERR_OK);
  // Reading high negative value::w
  result = read_inputs();
  EXPECT_EQ(target_value, -parameters.i_neg_max);
  EXPECT_EQ(result, ERR_OK);
}

TEST_F(RteTest, CurrentValue) {
  using ::testing::SetArgPointee;
  uint8_t result;
  int32_t target = 20;
  PidParams in_par;
  in_par.i_pos_min = 10;
  in_par.i_neg_min = 15;
  in_par.i_pos_max = 1000;
  in_par.i_neg_max = 900;

  EXPECT_CALL(*_rte, rte_pid_read_params(_))
    .Times(1)
    .WillOnce(DoAll(SetArgPointee<0>(in_par),
                    Return(ERR_OK)));
  EXPECT_CALL(*_rte, rte_pid_read_target_value(_))
    .Times(5)
    .WillRepeatedly(DoAll(SetArgPointee<0>(target), Return(ERR_OK)));
  EXPECT_CALL(*_rte, rte_pid_read_current_value(_))
    .Times(5)
    .WillOnce(DoAll(SetArgPointee<0>(12), Return(ERR_MEM_ACCES)))
    .WillOnce(DoAll(SetArgPointee<0>(9), Return(ERR_OK)))
    .WillOnce(DoAll(SetArgPointee<0>(-14), Return(ERR_OK)))
    .WillOnce(DoAll(SetArgPointee<0>(1001), Return(ERR_OK)))
    .WillOnce(DoAll(SetArgPointee<0>(-901), Return(ERR_OK)));
  EXPECT_CALL(*_rte, rte_pid_read_elapsed_time(_))
    .Times(2)
    .WillRepeatedly(DoAll(SetArgPointee<0>(0), Return(ERR_OK)));
  init_pid();
  // Error reading:
  result = read_inputs();
  EXPECT_EQ(result, ERR_MEM_ACCES);
  // Reading low positive value:
  result = read_inputs();
  EXPECT_EQ(target_value, target);
  EXPECT_EQ(current_value, 0);
  EXPECT_EQ(elapsed_time, 0);
  EXPECT_EQ(result, ERR_OK);
  // Reading low negative value:
  result = read_inputs();
  EXPECT_EQ(target_value, target);
  EXPECT_EQ(current_value, 0);
  EXPECT_EQ(elapsed_time, 0);
  EXPECT_EQ(result, ERR_OK);
  // Reading high positive value:
  result = read_inputs();
  EXPECT_EQ(target_value, target);
  EXPECT_EQ(current_value, parameters.i_pos_max);
  EXPECT_EQ(elapsed_time, 0);
  EXPECT_EQ(result, ERR_OUT_RANGE);
  // Reading high negative value:
  result = read_inputs();
  EXPECT_EQ(target_value, target);
  EXPECT_EQ(current_value, -parameters.i_neg_max);
  EXPECT_EQ(elapsed_time, 0);
  EXPECT_EQ(result, ERR_OUT_RANGE);
}

TEST_F(RteTest, ElapsedTime) {
  EXPECT_CALL(*_rte, rte_pid_read_target_value(_))
    .Times(1)
    .WillOnce(DoAll(SetArgPointee<0>(0), Return(ERR_OK)));
  EXPECT_CALL(*_rte, rte_pid_read_current_value(_))
    .Times(1)
    .WillOnce(DoAll(SetArgPointee<0>(0), Return(ERR_OK)));
  EXPECT_CALL(*_rte, rte_pid_read_elapsed_time(_))
    .Times(1)
    .WillOnce(DoAll(SetArgPointee<0>(0), Return(ERR_MEM_ACCES)));
  uint8_t result = read_inputs();
  EXPECT_EQ(result, ERR_MEM_ACCES);
}

TEST(PidTest, SystemStepResponse) {
  // Control parameters:
  uint32_t dtime = 1;
  uint32_t simulation_time = 0;
  int32_t target = 1000;
  // System parameters:
  float k = 1;
  float tau = 100;
  float response;
  float free_resp;
  SystemModel ctrl_model(k, tau);
  SystemModel free_model(k, tau);
  // Output file:
  std::remove("/home/alberto/samba/model.csv");
  std::ofstream outfile;
  outfile.open("/home/alberto/samba/model.csv",
               std::ofstream::out | std::ofstream::app);
  // Initialise the system: 
  parameters.p = 10.0;
  parameters.i = 0.05;
  parameters.d = 0.0;
  response = ctrl_model.system_response(dtime, 0);
  target_value = target;
  elapsed_time = dtime;
  // PID step response test:
  for(int idx = 0; idx < 1000; idx++){
    simulation_time += elapsed_time;
    free_resp = free_model.system_response(dtime, target);
    if (response <= INT32_MAX){
      current_value = (int32_t)response;
    } else{
      current_value = INT32_MAX;
    }
    pid();
    outfile << simulation_time  << ";" <<
               free_resp << ";" <<
               response << ";" <<
               control_signal << std::endl; 
    response = ctrl_model.system_response(dtime, control_signal);
  }
  outfile.close();
} 

TEST_F(RteTest, WriteOutputs) {
  using ::testing::Pointee;
  uint8_t result;
  parameters.o_neg_max = 1000;
  parameters.o_neg_min = 5;
  parameters.o_pos_max = 700;
  parameters.o_pos_min = 9;
  // Test a valid positive value:
  control_signal = 10;
  EXPECT_CALL(*_rte, rte_pid_write_control_signal(Pointee(control_signal)))
    .Times(1);
  result = write_outputs();
  EXPECT_EQ(result, ERR_OK);
  // Test a valid negative value:
  control_signal = -6;
  EXPECT_CALL(*_rte, rte_pid_write_control_signal(Pointee(control_signal)))
    .Times(1);
  result = write_outputs();
  EXPECT_EQ(result, ERR_OK);
  // Test a low positive value: 
  control_signal = 8;
  EXPECT_CALL(*_rte, rte_pid_write_control_signal(Pointee(0)))
    .Times(1);
  result = write_outputs();
  EXPECT_EQ(result, ERR_OK);
  // Test a low negative value: 
  control_signal = -4;
  EXPECT_CALL(*_rte, rte_pid_write_control_signal(Pointee(0)))
    .Times(1);
  result = write_outputs();
  EXPECT_EQ(result, ERR_OK);
  // Test a high positive value: 
  control_signal = 701;
  EXPECT_CALL(*_rte, rte_pid_write_control_signal(Pointee(parameters.o_pos_max)))
    .Times(1);
  result = write_outputs();
  EXPECT_EQ(result, ERR_OK);
  // Test a high negative value: 
  control_signal = -1001;
  EXPECT_CALL(*_rte, rte_pid_write_control_signal(Pointee(-parameters.o_neg_max)))
    .Times(1);
  result = write_outputs();
  EXPECT_EQ(result, ERR_OK);
}

TEST_F(RteTest, PidTask) {
  using ::testing::SetArgPointee;
  using ::testing::Pointee;
  using ::testing::SaveArg;
  // Control parameters:
  PidParams in_par;
  in_par.p = 10.0;
  in_par.i = 0.05;
  in_par.d = 0;
  in_par.i_pos_min = 4;
  in_par.i_neg_min = 4;
  in_par.i_pos_max = 300;
  in_par.i_neg_max = 300;
  in_par.o_pos_min = 1;
  in_par.o_neg_min = 1;
  in_par.o_pos_max = 255;
  in_par.o_neg_max = 255;
  in_par.calibrated = 0;
  uint32_t dtime = 1;
  uint32_t simulation_time = 0;
  int32_t target = 100;
  int32_t *point_arg;
  uint8_t result;
  // System parameters:
  float k = 1;
  float tau = 100;
  float response = 0;
  float free_resp;
  SystemModel ctrl_model(k, tau);
  SystemModel free_model(k, tau);
  // Output file:
  std::remove("/home/alberto/samba/pid_task.csv");
  std::ofstream outfile;
  outfile.open("/home/alberto/samba/pid_task.csv",
               std::ofstream::out | std::ofstream::app);

  EXPECT_CALL(*_rte, rte_pid_read_params(_))
    .Times(1)
    .WillOnce(DoAll(SetArgPointee<0>(in_par),
                    Return(ERR_OK)));
  EXPECT_CALL(*_rte, rte_pid_read_target_value(_))
    .WillRepeatedly(DoAll(SetArgPointee<0>(target),
                          Return(ERR_OK)));
  EXPECT_CALL(*_rte, rte_pid_read_elapsed_time(_))
    .WillRepeatedly(DoAll(SetArgPointee<0>(dtime),
                          Return(ERR_OK)));
  init_pid();
  // PID task response test:
  for(int idx = 0; idx < 1000; idx++){
    simulation_time += dtime;
    free_resp = free_model.system_response(dtime, target);
    EXPECT_CALL(*_rte, rte_pid_read_current_value(_))
      .Times(1)
      .WillRepeatedly(DoAll(SetArgPointee<0>(response),
                            Return(ERR_OK)));
    EXPECT_CALL(*_rte, rte_pid_write_control_signal(_))
      .Times(1)
      .WillRepeatedly(DoAll(SaveArg<0>(&point_arg),
                      Return(ERR_OK)));
    result = pid_task();
    EXPECT_EQ(result, ERR_OK);
    EXPECT_EQ(*point_arg, control_signal);
    outfile << simulation_time  << ";" <<
               free_resp << ";" <<
               response << ";" <<
               control_signal << std::endl; 
    response = ctrl_model.system_response(dtime, control_signal);
  }
  outfile.close();
}

