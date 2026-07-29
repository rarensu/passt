/* SPDX-License-Identifier: GPL-2.0-or-later
 * Copyright Red Hat
 * Author: Stefano Brivio <sbrivio@redhat.com>
 * Author: David Gibson <david@gibson.dropbear.id.au>
 */

#ifndef ISOLATION_H
#define ISOLATION_H

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

struct initial_fd_snapshot {
	int *arr;
	size_t count;
};

void isolate_initial(void);
void snapshot_initial_fds(struct initial_fd_snapshot *ifds);
void isolate_fds(struct initial_fd_snapshot *ifds, int keep_fd);
void isolate_user(const struct ctx *c, uid_t uid, gid_t gid, bool use_userns,
		  const char *userns);
int isolate_prefork(const struct ctx *c);
void isolate_postfork(const struct ctx *c);

#endif /* ISOLATION_H */
