//publisher.c

#include <topic.h>

/* create topic metadata */
ORB_DEFINE(random_integer);

/* file handle that will be used for publishing */
static int topic_handle;

int
init()
{
	/* generate the initial data for first publication */
	struct random_integer_data rd = { .r = random(), };

	/* advertise the topic and make the initial publication */
	topic_handle = orb_advertise(ORB_ID(random_integer), &rd);
}

int
update_topic()
{
	/* generate a new random number for publication */
	struct random_integer_data rd = { .r = random(), };

	/* publish the new data structure */
	orb_publish(ORB_ID(random_integer), topic_handle, &rd);
}