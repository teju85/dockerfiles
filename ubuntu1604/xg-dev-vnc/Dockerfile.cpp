FROM xgboost-dev:latest

#include "../../reusables/vnc"
ENTRYPOINT ["/runas.sh", "/vncserver.sh"]
