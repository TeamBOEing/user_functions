void setStopValue(int stop)
{
  if (stopValue < 1475)
    Serial.println("Stop value below acceptable threshold, please try again.");
  else if (stopValue > 1525)
    Serial.println("Stop value above acceptable threshold, please try again.");
  else
    stopValue = stop;
}

void leftMotor(int speed)
{
  if (speed > 100)
  {
    Serial.println("Left motor speed above allowable forward threshold. Adjusting to max forward speed.");
    speed == 100;
  } else if (speed < -100)
  {
    Serial.println("Left motor speed above allowable backward threshold. Adjusting to max backward speed.");
    speed == -100;
  }

  if (speed == 0)
  {
    if (leftServo.attached())
      leftServo.detach();
  } else
  {
    if (!leftServo.attached())
      leftServo.attach(MOTOR_LEFT);

    leftServo.writeMicroseconds(stopValue + speed);
  }
}

void rightMotor(int speed)
{
  if (speed > 100)
  {
    Serial.println("Right motor speed above allowable forward threshold. Adjusting to max forward speed.");
    speed == 100;
  } else if (speed < -100)
  {
    Serial.println("Right motor speed above allowable backward threshold. Adjusting to max backward speed.");
    speed == -100;
  }

  if (speed == 0)
  {
    if (rightServo.attached())
      rightServo.detach();
  } else
  {
    if (!rightServo.attached())
      rightServo.attach(MOTOR_RIGHT));

    rightServo.writeMicroseconds(stopValue - speed);
  }
}

int getLeftLight()
{
  return analogRead(LDR_LEFT);
}

int getRightLight()
{
  return analogRead(LDR_RIGHT);
}

