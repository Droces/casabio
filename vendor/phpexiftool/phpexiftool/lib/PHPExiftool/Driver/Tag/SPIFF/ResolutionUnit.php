<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\SPIFF;

use PHPExiftool\Driver\AbstractTag;

class ResolutionUnit extends AbstractTag
{

    protected $Id = 17;

    protected $Name = 'ResolutionUnit';

    protected $FullName = 'JPEG::SPIFF';

    protected $GroupName = 'SPIFF';

    protected $g0 = 'APP8';

    protected $g1 = 'SPIFF';

    protected $g2 = 'Image';

    protected $Type = 'int8u';

    protected $Writable = false;

    protected $Description = 'Resolution Unit';

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'None',
        ),
        1 => array(
            'Id' => 1,
            'Label' => 'inches',
        ),
        2 => array(
            'Id' => 2,
            'Label' => 'cm',
        ),
    );

}
