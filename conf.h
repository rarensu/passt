/* SPDX-License-Identifier: GPL-2.0-or-later
 * Copyright (c) 2021 Red Hat GmbH
 * Author: Stefano Brivio <sbrivio@redhat.com>
 */

#ifndef CONF_H
#define CONF_H

#define PASS_FDS_MAX	1024

/**
 * struct fd_opts - File descriptor options parsed from command line
 * @pass_fds_v:	File descriptors supplied via --pass-fd
 * @pass_fds_c:	Number of file descriptors in @pass_fds_v
 * @tap:	Tap file descriptor supplied via --fd, or -1
 */
struct fd_opts {
	int pass_fds_v[PASS_FDS_MAX];
	int pass_fds_c;
	int tap;
};

enum passt_modes conf_mode(int argc, char *argv[]);
void conf_fds(int argc, char **argv, struct fd_opts *fds);
void conf(struct ctx *c, int argc, char **argv);
void conf_listen_handler(struct ctx *c, uint32_t events);
void conf_handler(struct ctx *c, uint32_t events);

#endif /* CONF_H */
