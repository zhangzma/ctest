//topic.h

/* declare the topic */
ORB_DECLARE(random_integer);

/* define the data structure that will be published where subscribers can see it */
struct random_integer_data {
	int r;
};