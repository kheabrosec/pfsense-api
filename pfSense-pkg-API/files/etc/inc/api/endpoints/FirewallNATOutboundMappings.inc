<?php

namespace API\Endpoints;

require_once("api/auto_loader.inc");

use API\Core\Endpoint;

class FirewallNATOutboundMappings extends Endpoint
{
    public function __construct() {
        # Assign the URL for this endpoint along with the Model it corresponds to.
        $this->url = "/api/v2/firewall/nat/outbound/mappings";
        $this->model_name = "OutboundNATMapping";
        $this->many = true;

        # Assign allowed request methods along with the privileges required for each
        $this->request_method_options = ["GET", "PUT"];
        $this->get_privileges = ["page-all", "page-firewall-rules"];

        # Construct the parent Endpoint object
        parent::__construct();
    }
}