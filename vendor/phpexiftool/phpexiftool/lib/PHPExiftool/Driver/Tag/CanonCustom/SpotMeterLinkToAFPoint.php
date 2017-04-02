<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\CanonCustom;

use PHPExiftool\Driver\AbstractTag;

class SpotMeterLinkToAFPoint extends AbstractTag
{

    protected $Id = 263;

    protected $Name = 'SpotMeterLinkToAFPoint';

    protected $FullName = 'CanonCustom::Functions2';

    protected $GroupName = 'CanonCustom';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'CanonCustom';

    protected $g2 = 'Camera';

    protected $Type = 'int32s';

    protected $Writable = true;

    protected $Description = 'Spot Meter Link To AF Point';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'Disable (use center AF point)',
        ),
        1 => array(
            'Id' => 1,
            'Label' => 'Enable (use active AF point)',
        ),
    );

}
