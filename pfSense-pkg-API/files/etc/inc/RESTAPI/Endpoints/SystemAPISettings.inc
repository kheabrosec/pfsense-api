<?php

namespace RESTAPI\Endpoints;

require_once("RESTAPI/autoloader.inc");

use RESTAPI\Core\Endpoint;

class SystemAPISettings extends Endpoint
{
    public function __construct() {
        # Set Endpoint attributes
        $this->url = "/RESTAPI/v2/system/RESTAPI/settings";
        $this->model_name = "RESTAPISettings";
        $this->request_method_options = ["GET", "PATCH"];
        $this->get_help_text = "Reads the current API settings.";
        $this->patch_help_text = "Updates the current API settings.";

        # Construct the parent Endpoint object
        parent::__construct();
    }
}