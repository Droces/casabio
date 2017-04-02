<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Minolta;

use PHPExiftool\Driver\AbstractTag;

class ExposureCompensationMode extends AbstractTag
{

    protected $Id = 'mixed';

    protected $Name = 'ExposureCompensationMode';

    protected $FullName = 'mixed';

    protected $GroupName = 'Minolta';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Minolta';

    protected $g2 = 'Camera';

    protected $Type = 'mixed';

    protected $Writable = true;

    protected $Description = 'Exposure Compensation Mode';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'Ambient and Flash',
        ),
        1 => array(
            'Id' => 1,
            'Label' => 'Ambient Only',
        ),
    );

}
