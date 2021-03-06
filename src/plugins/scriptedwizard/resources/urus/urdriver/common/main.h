/***************************************************************
 * Name:      [FILENAME_PREFIX]App.h
 * Purpose:   Defines Application Class
 * Author:    [AUTHOR_NAME] ([AUTHOR_EMAIL])
 * Created:   [NOW]
 * Copyright: [AUTHOR_NAME] ([AUTHOR_WWW])
 * License:
 **************************************************************/

#pragma once

#include <AP_HAL/AP_HAL.h>
#if CONFIG_HAL_BOARD == [HAL_BOARD_CONFIGDEF] && \
    CONFIG_SHAL_CORE == [SHAL_COREDEF]

#define [CLASS_PREFIX_DEF]_MAX_BACKENDS 1

class AP_[CLASS_PREFIX]_Backend;

class AP_[CLASS_PREFIX] {

    friend class AP_[CLASS_PREFIX]_Backend;

public:

    enum ProcessMode {
        AutoProcess = 0,
        LoopProcess
    };

    AP_[CLASS_PREFIX]();

    /** Wrap only, make some people happy, this will be
      * removed in the future.
      * By default init() call to configure() in auto process
      * @param None.
      * @return None.
      */
    void init() {
        configure();
    }

    /** Configure the backend with their implementations.
      * By default configure() set "auto process" mode on
      * process() backend function.
      * @param  process_mode:
      *         [AutoProcess] - Update process run in the scheduled
      *         callback. This is the default mode.
      *         [LoopProcess] - Update process run not in scheduled
      *         callback. udpate() need to be called in somewhere
      *         to see the action, otherwise nothing happen.
      * @return None.
      */
    void configure(ProcessMode process_mode = ProcessMode::AutoProcess);

    /** Update the backend process.
      * @param  none.
      * @return None.
      */
    void update();

private:

    AP_[CLASS_PREFIX]_Backend *_backends[[CLASS_PREFIX_DEF]_MAX_BACKENDS];
    uint8_t _backend_count;
    bool _backends_configuring:1;

    // load backend drivers
    bool _add_backend(AP_[CLASS_PREFIX]_Backend *backend);
    void _configure_backends();
    void _configure_backends(ProcessMode process_mode);
};

#endif
