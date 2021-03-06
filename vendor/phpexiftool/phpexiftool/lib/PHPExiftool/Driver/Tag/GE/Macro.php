<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\GE;

use PHPExiftool\Driver\AbstractTag;

class Macro extends AbstractTag
{

    protected $Id = 514;

    protected $Name = 'Macro';

    protected $FullName = 'GE::Main';

    protected $GroupName = 'GE';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'GE';

    protected $g2 = 'Camera';

    protected $Type = 'int16u';

    protected $Writable = true;

    protected $Description = 'Macro';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'Off',
        ),
        1 => array(
            'Id' => 1,
            'Label' => 'On',
        ),
    );

}
