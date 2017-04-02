<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\GPS;

use PHPExiftool\Driver\AbstractTag;

class GPSStatus extends AbstractTag
{

    protected $Id = 'mixed';

    protected $Name = 'GPSStatus';

    protected $FullName = 'mixed';

    protected $GroupName = 'GPS';

    protected $g0 = 'mixed';

    protected $g1 = 'mixed';

    protected $g2 = 'mixed';

    protected $Type = 'string';

    protected $Writable = false;

    protected $Description = 'GPS Status';

    protected $Values = array(
        'A' => array(
            'Id' => 'A',
            'Label' => 'Measurement Active',
        ),
        'V' => array(
            'Id' => 'V',
            'Label' => 'Measurement Void',
        ),
    );

    protected $local_g1 = 'mixed';

    protected $local_g2 = 'mixed';

    protected $flag_Permanent = 'mixed';

    protected $MaxLength = 'mixed';

}
