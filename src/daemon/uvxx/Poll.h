#ifndef UVXX_POll_H
#define UVXX_POll_H

#include "Handle.h"

namespace uvxx {

class Poll : public HandleT<uv_poll_t> {
public:
    explicit Poll(const std::shared_ptr<Loop> &loop, int fd);

    bool start(int events);
    bool stop();

    void onEvent(const std::function<void(int events)> &cb) { eventCb_ = cb; };

private:
    std::function<void(int events)> eventCb_{nullFunc{}};

    void pollCb(uv_poll_t *handle, int status, int events);
};

} // namespace uvxx

#endif // !UVXX_POll_H