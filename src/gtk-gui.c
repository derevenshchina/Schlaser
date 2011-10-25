/******************************* Schlaser Header ******************************
Purpose: 
   gtk UI implementation
Reference:
   None
Programmers:
   E. Kent Golding -- Oct 2011 -- Initial Implementation
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "schlaser.h"

//void GdkPixbuf *create_pixbuf(const gchar * filename)
GdkPixbuf *create_pixbuf(const gchar * filename)
{
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   if(!pixbuf) {
      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
   }
   return pixbuf;
}

gint count = 1337;
char buf[5];

static void increase(GtkWidget *widget, gpointer label)
{
   count++;

   sprintf(buf, "%d", count);
   gtk_label_set_text(label, buf);
}

static void decrease(GtkWidget *widget, gpointer label)
{
   count--;

   sprintf(buf, "%d", count);
   gtk_label_set_text(label, buf);
}

void init_ui(int argc, char **argv)
{
   GtkWidget *window;
   GtkWidget *frame;
   GtkWidget *label;
   GtkWidget *plus;
   GtkWidget *minus;

   gtk_init(&argc, &argv);
   
   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   g_set_application_name ("schlaser");
   gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("images/beer-mug.png"));
   gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
   gtk_window_set_default_size(GTK_WINDOW(window), 250, 180);
   gtk_window_set_title(GTK_WINDOW(window), "schlaser");

   frame = gtk_fixed_new();
   gtk_container_add(GTK_CONTAINER(window),frame);

   plus = gtk_button_new_with_label("increase (+)");
   gtk_widget_set_size_request(plus, 80, 35);
   gtk_fixed_put(GTK_FIXED(frame), plus, 50, 20);

   minus = gtk_button_new_with_label("decrease (-)");
   gtk_widget_set_size_request(minus, 80, 35);
   gtk_fixed_put(GTK_FIXED(frame), minus, 50, 80);

   label = gtk_label_new("1337");
   gtk_fixed_put(GTK_FIXED(frame), label, 190, 58);

   gtk_widget_show_all(window);

   g_signal_connect(window, "destroy",
      G_CALLBACK (gtk_main_quit), NULL);

   g_signal_connect(plus, "clicked", G_CALLBACK(increase), label);


   g_signal_connect(minus, "clicked", G_CALLBACK(decrease), label);

   return;
}

void run_ui(void)
{
   gtk_main();
}
