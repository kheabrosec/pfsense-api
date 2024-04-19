<?php

namespace RESTAPI\Endpoints;

require_once 'RESTAPI/autoloader.inc';

use RESTAPI\Core\Endpoint;

class ServicesCronJobsEndpoint extends Endpoint {
    public function __construct() {
        # Set Endpoint attributes
        $this->url = '/api/v2/services/cron/jobs';
        $this->model_name = 'CronJob';
        $this->many = true;
        $this->request_method_options = ['GET', 'PUT'];

        # Construct the parent Endpoint object
        parent::__construct();
    }
}