#include <libnotify/notify.h>
#include <mpd/client.h>
#include <stdio.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

/**
 * Obviously super sloppy, not checking for nulls is especially dangerous
 * Just wanted to run this up quickly to see what c functions would be
 * needed on the ocaml side.
 */
int main () {
    notify_init ("MPD Notification");
    NotifyNotification * notification = notify_notification_new ("MPD Notification", "", "");

    struct mpd_connection * conn = mpd_connection_new("localhost", 6600, 0);
    struct mpd_status * status;
    struct mpd_song * song;

    GdkPixbuf * pix_buf;
    while (1) {
        mpd_run_idle(conn);
        status = mpd_run_status(conn);
        song = mpd_run_get_queue_song_id(conn, mpd_status_get_song_id(status));
        const char * title = mpd_song_get_tag(song, MPD_TAG_TITLE, 0);
        const char * artist = mpd_song_get_tag(song, MPD_TAG_ARTIST, 0);
        const char * album = mpd_song_get_tag(song, MPD_TAG_ALBUM, 0);

        pix_buf = gdk_pixbuf_new_from_file("", NULL);

        notify_notification_update(notification, title, album, "");
        notify_notification_set_icon_from_pixbuf(notification, pix_buf);
        notify_notification_show (notification, NULL);

        mpd_status_free(status);
        mpd_song_free(song);
        g_object_unref(pix_buf);
    }

    mpd_connection_free(conn);

    return 0;
}
