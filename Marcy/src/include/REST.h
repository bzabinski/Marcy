/*
 * REST.h
 *
 *  Created on: Jun 11, 2014
 *      Author: beth
 */

#ifndef REST_H_
#define REST_H_

int testServer(void);

int createNodes(int numOfNodes);

static char *request(const char *url, char *postdata, int datareturn);

#endif /* REST_H_ */
