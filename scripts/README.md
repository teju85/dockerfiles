# Intro
This document tries to explain the usage of 'scripts/launch' script in detail.
For all the options supported by this script, look at its '-h' option.
This wrapper script has ability to:
1. Run as current user
2. Mount pwd as /work and set this as pwd in the container
And it can do all these without having to rebuild your docker image!
For example, in order to run the pytorch container as current user and start a
terminal inside it:
```bash
$ ./scripts/launch -user pytorch:0.1.12 /bin/bash
```
The script will also print out the raw commandline it uses to launch such a
container to the terminal. If need be, one can also directly use this command.

# PWD mounting
This script can mount the current work directory (on host) as a volume under
the container. This is enabled by default. This will always mount the current
directory as '/work' inside the container.

# runas
There are 3 ways currently supported:
1. root - (default) just open the container as root
2. user - this would mean that the current user's UID will be exported into the
container and before starting the container, a couple of extra scripts will be
run in order to create a new user with the same UID. This can be useful,
especially when one is trying to write files into the current directory and thus
can face permission issues.
3. uid:gid - the script will use the '-u' option of docker in order to setup the
current user in the container. No extra scripts will be run as in the previous
case. This is useful, especially when one is running from a NFS automounted dir.
Typically, such dirs will not have sufficient permissions to be mounted through
the '-v' option of docker. This option is also useful when one doesn't want to
run any extra scripts to establish current user in the container (for whatsoever
reasons). In case you are trying to use this option due to NFS permission
issues, then also pass the '-nfsmount' option (see below).

# nfs-mount
If the current directory (or any other directory) that you want to be mounted in
the container is not possible due to insufficient permissions, then use this
option, '-nfsmount' to mount the *nfs-root* of the current directory as '/work'
inside the container. Since this option will end up using the '--mount' option
of docker, for NFS mounting, it is recommend that you use docker >= v17.03.

Note: some of the ideas are inspired from ryanolson/luda (Thanks!).
