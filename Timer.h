class Timer {
  typedef int (*OperationCallback)();

 private:
  long endtime = 0;
  long totalWaitTime = 0;

 public:
  Timer(long _totalWaitTime) { totalWaitTime = _totalWaitTime; };

  void init() {
    if (endtime > 0) return;
    endtime = millis() + totalWaitTime;
  };

  void cancel() {
    endtime = 0;
    return;
  }

  void counter(OperationCallback callback) {
    if (endtime == 0) return;
    if (millis() <= endtime) return;
    endtime = 0;
    callback();
    return;
  };
};