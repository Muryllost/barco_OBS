
void robot_backward(unsigned char v) {
  motor3.setSpeed(v);
  motor3.run(BACKWARD);
  motor4.setSpeed(v);
  motor4.run(FORWARD);


}  //end robot forward

void robot_forward(unsigned char v) {
  motor3.setSpeed(v);
  motor3.run(FORWARD);
  motor4.setSpeed(v);
  motor4.run(BACKWARD);

}  //end robot backward

void robot_left(unsigned char v) {
  motor3.setSpeed(v);
  motor3.run(BACKWARD);
  motor4.setSpeed(v);
  motor4.run(FORWARD);
}  //end robot left

void robot_right(unsigned char v) {
  motor3.setSpeed(v);
  motor3.run(FORWARD);
  motor4.setSpeed(v);
  motor4.run(BACKWARD);
}  //end robot left


void robot_stop(unsigned char v) {
  motor3.setSpeed(v);
  motor3.run(RELEASE);
  motor4.setSpeed(v);
  motor4.run(RELEASE);
}
