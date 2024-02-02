<?php

namespace RESTAPI\Endpoints;

require_once 'RESTAPI/autoloader.inc';

use RESTAPI\Core\Endpoint;

class FirewallSchedulesEndpoint extends Endpoint
{
    public function __construct()
    {
        # Set Endpoint attributes
        $this->url = '/api/v2/firewall/schedules';
        $this->model_name = 'FirewallSchedule';
        $this->many = true;
        $this->request_method_options = ['GET', 'PUT'];

        # Construct the parent Endpoint object
        parent::__construct();
    }
}