open MpdnotifyNative

let do_work notification mpd_connection =
    mpd_run_idle mpd_connection;
    let info = mpd_get_info mpd_connection in
    update_notification notification "" "" "";
    show_notification notification;
    do_work notification mpd_connection

let () =
    let notification = new_notification "MPD Notification" in
    let mpd_connection = mpd_connect "localhost" 6600 in
    do_work notification mpd_connection
