#ifndef serialProcess_h
#define serialProcess_h

namespace serialProcess {
    void sendVars(int *arrayPtr);
};

namespace dataProcess {
  void collectVars(int *arrayPtr);
  int processVars(int input, int upper, int lower, int deadzone, int upperPWM, int lowerPWM);

}

#endif
